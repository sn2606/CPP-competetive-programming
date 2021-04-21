package pack1.subpack1;
import pack1.Person;

public class Student extends Person {
    String regno;
    double cgpa;

    public Student(String name, int age, long phoneno, String regno, double cgpa) {
        super(name, age, phoneno);
        this.regno = regno;
        this.cgpa = cgpa;
    }

    public String getRegno() {
        return this.regno;
    }

    public double getCGPA() {
        return this.cgpa;
    }

    public void dispStudent() {
        super.dispInfo();
        System.out.println("Reg No: " + regno);
        System.out.println("CGPA: " + cgpa);
    }
    
}
