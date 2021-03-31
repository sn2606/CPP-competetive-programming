// Create an interface Shape with abstract methods for calculating area and
// getting the shape name. Create a class called Point which implements the
// interface with the data members area and radius. Inherit the class Circle
// from Point, in which override the method for calculating area and
// displaying the shape name accordingly. Create the class Cylinder from
// Circle and implement the interface methods. Provide the method for
// calculating the volume of the cylinder. Create a driver class containing the
// array of shapes. Calculate the area and volume of the shapes.
// Note :
// Area of Circle : π * radius2
// Area of Cylinder: 2 * π * radius * height
// Volume of Cylinder : π * radius2 * height

import java.lang.Math;

// If the overridden or hidden method is public, then the overriding 
// or hiding method must be public; otherwise, a compile-time error occurs.
// If the overridden or hidden method is protected, then the overriding 
// or hiding method must be protected or public; otherwise, a compile-time error occurs.
// If the overridden or hidden method has default (package) access, then the overriding 
// or hiding method must not be private; otherwise, a compile-time error occurs.
// Note that a private method cannot be hidden or overridden in the technical sense of those terms. 
// This means that a subclass can declare a method with the same signature as a private method in 
// one of its superclasses, and there is no requirement that the return type or throws clause of 
// such a method bear any relationship to those of the private method in the superclass.
interface Shape{
    float area();
    float volume();
    void shapeName();
}


class Point implements Shape{
    float area;
    float radius;
    float height;
    String shape;
    public float area(){
        return 0;
    }
    public void shapeName(){
        System.out.println("This is a " + shape);
    }
    public float volume() {
        return 0;
    }
}

class Circle extends Point{
    String shape = "Circle";
    public float area(){
        return (float) (Math.PI*radius*radius);
    }
    public void shapeName(){
        System.out.println("This is a " + shape);
    }
}

class Cylinder extends Circle{
    String shape = "Cylinder";
    public float area(){
        return (float) (Math.PI*radius*height);
    }
    public float volume(){
        return (float) (Math.PI*this.radius*this.radius*this.height);
    }
    public void shapeName(){
        System.out.println("This is a " + shape); }
}


public class AbstractIn {
    public static void main(String[] args){
        Point arr[] = {new Circle(), new Cylinder()};
        arr[0].shapeName();
        arr[0].radius = 12.2f;
        System.out.println("Radius = " + arr[0].radius + " Area = " + arr[0].area());
        arr[1].shapeName();
        arr[1].radius = 13.2f;
        arr[1].height = 5.2f;
        System.out.println("Radius = " + arr[1].radius + " Height = " + arr[1].height + " Area = " +
                arr[1].area() + " Volume = " + arr[1].volume());
    }
}
