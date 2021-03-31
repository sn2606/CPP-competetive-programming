package pack1;

public class Person {
    String name;
    int age;
    long phoneno;

    public Person() {}

    public Person(String name, int age, long phoneno) {
        this.name = name;
        this.age = age;
        this.phoneno = phoneno;
    }

    public String getName() {
        return this.name;
    }
    
    public int getAge() {
        return this.age;
    }

    public long getPhone() {
        return this.phoneno;
    }

    public void dispInfo() {
        System.out.println("Name: " + this.name);
        System.out.println("Age: " + this.age);
        System.out.println("Phone No.: " + this.phoneno);
    }
}
