import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;
import java.util.Arrays;
import java.util.Comparator;

// Hostel registration program based on CGPA of student in Java 
// (Multi-threading concepts and file handling with .txt file). :- 
// Create classes Students and HostelBlocks with necessary details. 
// Store the objects as collections in a File. Create threads for Hostel_Incharge 
// to allocate rooms based on cgpa. If incharges are trying to allocate the same rooms, 
// handle the situation using inter thread communication

class Student implements Serializable {
    String name;
    String regno;
    double cgpa;
    int prefRoom; // preference given of room no. by the student
    String prefBlock;
    int newRoom;

    Student (String name, String regno, double cgpa, int prefRoom, String prefBlock) { 
        this.name = name;
        this.regno = regno;
        this.cgpa = cgpa;
        this.prefRoom = prefRoom; 
        this.prefBlock = prefBlock;
    }

    void displayStudentInfo() {
        System.out.println("Details: " + this.regno + " " + this.name + " " + this.cgpa + " " + this.prefRoom);
    }

    void displayStudentAllocated() {
        System.out.println("Details: " + this.regno + " " + this.name + " " + this.cgpa + " " + this.newRoom + " " + this.prefBlock);
    }
}

class Room implements Serializable {
    int roomno;
    int occupied;
    int size;

    Room() {
        size = 2; // there are at least 2 beds in every room on campus
    }

    Room(int roomno, int occupied, int size) {
        this.roomno = roomno;
        this.occupied = occupied;
        this.size = size;
    }
}

class HostelBlock implements Serializable {
    String blockName;
    Room r[] = new Room[10];
    int roomn = 0;
    static int booking;

    HostelBlock(String name, int rooms, int[] roomnos) {
        blockName = name;
        roomn = rooms;
        for(int i = 0; i < rooms; i++) {
            r[i] = new Room(roomnos[i], 0, 4);
        }
    }

    synchronized int bookRoom(Student[] priorCGPA) {
        for(Student stu : priorCGPA) {
            if(stu.newRoom == 0) {
                try {
                    for(int i = 0; i < roomn; i++) {
                    // for(Room stuRoom : r) {
                        Room stuRoom = r[i];

                        if((stu.prefBlock.compareTo(blockName) == 0) && (stuRoom.roomno == stu.prefRoom) && (stuRoom.occupied < stuRoom.size)) {
                            stu.newRoom = stuRoom.roomno;
                            // System.out.println(stuRoom.roomno);
                            stuRoom.occupied++;
                            booking++;
    
                            // if(booking == 1){
                            //     wait();
                            // }
                        }
    
                        // if(booking > 1 && booking < priorCGPA.length - 2) {
                        //     notifyAll();
                        //     wait();
                        // }
                    }

                } catch (Exception e) {
                    System.out.println(e);
                }
                
                for(Student s : priorCGPA) {
                    s.displayStudentAllocated();
                }
            }

            if(booking == priorCGPA.length){
                return 1;
            }
        }

        return 0;
    }   

}

class HostelIncharge extends Thread {
    HostelBlock H;
    Student listStudent[];

    HostelIncharge(HostelBlock H, Student[] listStudent) {
        this.H = H;
        this.listStudent = listStudent;
    }

    public void run() {
        int bookingStatus = 0;

        try {
            bookingStatus = H.bookRoom(listStudent);
        } catch (Exception e) {
            e.printStackTrace();
        }

        // System.out.println(bookingStatus);

        if(bookingStatus == 1) {
            interrupt();
        }
    }
}

public class HostelReg {
    public static void main(String[] args) {
        int nos = 5;
        Student stuArr[] = new Student[nos];
        stuArr[0] = new Student("Stu1", "19BCE0001", 9.8, 115, "A");
        stuArr[1] = new Student("Stu2", "19BCE0002", 9.9, 102, "F");
        stuArr[2] = new Student("Stu3", "19BCE0003", 8.9, 101, "F");
        stuArr[3] = new Student("Stu4", "19BCE0004", 9.1, 105, "F");
        stuArr[4] = new Student("Stu5", "19BCE0005", 8.5, 111, "A");

        Student newStuArr[] = new Student[nos];

        try {
            // Write input in file
            FileOutputStream fout = new FileOutputStream("C:\\Users\\S K Nayak\\Documents\\CPP Problems\\Java Concepts\\HostelReg.txt");
            ObjectOutputStream os = new ObjectOutputStream(fout);
            os.writeObject(stuArr);
            os.close();
            fout.close();

            // Reading input from the file
            FileInputStream fin = new FileInputStream("C:\\Users\\S K Nayak\\Documents\\CPP Problems\\Java Concepts\\HostelReg.txt");
            ObjectInputStream is = new ObjectInputStream(fin);
        
            // what is the available method? -> look up
            while(fin.available() != 0){
                newStuArr = (Student[])is.readObject();
            }
            is.close();
            fin.close();
        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        } catch (ClassNotFoundException e) {
            System.out.println(e);
        }
        

        // sorting the array of objects
        // Collection, new Comparator -> to revise
        Arrays.sort(newStuArr, new Comparator<Student>() {
            public int compare(Student s1, Student s2) {
                if(s1.cgpa < s2.cgpa){
                    return 1;
                }
                if(s1.cgpa > s2.cgpa){
                    return -1;
                }
                return 0;
            }
        });

        // for(Student s : newStuArr) {
        //     s.displayStudentInfo();
        // }

        int[] arooms = {111, 112, 113, 114, 115};
        int[] frooms = {101, 102, 103, 104, 105};

        HostelBlock h1 = new HostelBlock("F", 5, frooms);
        HostelBlock h2 = new HostelBlock("A", 5, arooms);

        HostelIncharge w1 = new HostelIncharge(h1, newStuArr);
        HostelIncharge w2 = new HostelIncharge(h2, newStuArr);

        w1.start();
        w2.start();

        // for(int i = 0; i < nos; i++){
        //     newStuArr[i].displayStudentAllocated();
        // }

    }
}