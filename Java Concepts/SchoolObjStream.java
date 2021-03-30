import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

class School implements Serializable {
    String name;
    int programmes;

    School(){}

    School(String name, int programmes){
        this.name = name;
        this.programmes = programmes;
    }

    void display() {
        System.out.println("Name: " + name);
        System.out.println("No. of programmes: " + programmes);
    }
}



public class SchoolObjStream {
    public static void main(String[] args) {

        try {
            School s1 = new School("School1", 7);
            School s2 = new School("School2", 6);
            School s3 = new School("School3", 5);

            FileOutputStream fos = new FileOutputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Lab Exercise\\SchoolObjStream.txt");
            ObjectOutputStream os = new ObjectOutputStream(fos);
            os.writeObject(s1);
            os.writeObject(s2);
            os.writeObject(s3);
            os.close();
            fos.close();
            
            FileInputStream fis = new FileInputStream("C:\\Users\\S K Nayak\\Documents\\CSE1007 Lab\\Lab Exercise\\SchoolObjStream.txt");
            ObjectInputStream is = new ObjectInputStream(fis);

            
            for(int i = 0; i < 3; i++){
                School s = new School();
                s = (School) is.readObject();
                s.display();
            }
            
            is.close();
            fis.close();

        } catch (Exception e) {
            System.out.println(e);
        }
                
    }
}
