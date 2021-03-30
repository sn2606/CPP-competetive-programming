import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.io.Serializable;

// Define a class ‘Donor’ to store the below mentioned details of  a blood donor.  
// Name, age, Address, Contact number, blood group, date of last donation 
// Create ‘n’ objects of this class for all the regular donors at Vellore. 
// Write these objects to a file. Read these objects from the file and display only those 
// donors’ details whose blood group is ‘A+ve’ and had not donated for the recent six months.

class Donor implements Serializable{
    String name;
    int age;
    String address;
    long contactNo;
    String bloodGroup;
    String dateLast;

    Donor(String name, int age, String address, long contactNo, String bloodGroup, String dateLast) {
        this.name = name;
        this.age = age;
        this.address = address;
        this.contactNo = contactNo;
        this.bloodGroup = bloodGroup;
        this.dateLast = dateLast;
    }

    void displayDonor(int i) {
        System.out.println("Donor " + i + ": ");
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
        System.out.println("Address: " + address);
        System.out.println("Contact No.: " + contactNo);
        System.out.println("Blood Group: " + bloodGroup);
        System.out.println("Last Donated: " + dateLast);
    }

    int difference() {
        int month = 3;
        int year = 2021;
        String[] arrs = dateLast.split("/"); 
        // System.out.println(dateLast);
        // for(String s : arrs){
        //     System.out.println(s);
        // }
        int arr[] = new int[arrs.length];

        for(int i = 0; i < arrs.length; i++) {
            arr[i] = Integer.parseInt(arrs[i]);
        }

        if(month + year < arr[1] + arr[2])
            return -1; // invalid date

        if(arr[2] == year){
            return (month - arr[1]);
        }else if(arr[2] == year-1){
            return (12 - arr[1] + month);
        }else{
            return ((12 * (year - 1 - arr[2])) + 12 - arr[1] + month);
        }
    }
}

public class DonorMain {
    public static void main(String[] args) {
        int n = 4;
        Donor d[] = new Donor[n];

        d[0] = new Donor("Donor1", 19, "Vellore", 999999999, "A+", "29/01/2019");
        d[1] = new Donor("Donor2", 20, "Vellore", 999999998, "A+", "19/01/2021");
        d[2] = new Donor("Donor3", 21, "Vellore", 999999988, "B+", "27/10/2020");
        d[3] = new Donor("Donor4", 22, "Vellore", 999999888, "O+", "26/06/2015");

        // System.out.println(d[0].difference());

        Donor nd[] = new Donor[n];

        try {
            // Write input in file
            FileOutputStream fout = new FileOutputStream("C:\\Users\\S K Nayak\\Documents\\CPP Problems\\Java Concepts\\Donor.txt");
            ObjectOutputStream os = new ObjectOutputStream(fout);
            for(int i = 0; i < d.length; i++) {
                os.writeObject(d[i]);
            }
            os.close();
            fout.close();

            // Reading input from the file
            FileInputStream fin = new FileInputStream("C:\\Users\\S K Nayak\\Documents\\CPP Problems\\Java Concepts\\Donor.txt");
            ObjectInputStream is = new ObjectInputStream(fin);
        
            int i = 0;
            // what is the available method? -> look up
            while(fin.available() != 0){
                nd[i] = (Donor)is.readObject();
                i++;
            }
            // System.out.println(i);
            is.close();
            fin.close();
        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        } catch (ClassNotFoundException e) {
            System.out.println(e);
        }

        for(int i = 0; i < nd.length; i++) {
            if((nd[i].bloodGroup.compareTo("A+") == 0) && (nd[i].difference() >= 6)){
                nd[i].displayDonor(i+1);
            }
        }        
    }
}