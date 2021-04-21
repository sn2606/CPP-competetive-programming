package pack2;
import pack1.subpack1.Student;

public class Test {
    public static void main(String[] args) {
        long phoneno = 9999;
        Student s1 = new Student("hello", 18, phoneno, "19BCE0977", 9.49);
        s1.dispInfo();
    }    
}
