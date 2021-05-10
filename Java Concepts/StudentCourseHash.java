import java.util.HashMap;
import java.util.List;
import java.util.LinkedHashMap;
import java.util.Arrays;
import java.util.Map;
import java.util.Scanner;


public class StudentCourseHash {
    public static void main(String[] args) {
        HashMap<String, List<String>> h1 = new LinkedHashMap<>();
        HashMap<String, String> h2 = new LinkedHashMap<>();

        List<String> subjects = Arrays.asList("Python", "Math", "C");
        h1.put("A",subjects);
        subjects = Arrays.asList("C","C++");
        h1.put("B",subjects);
        subjects = Arrays.asList("C++","Physics","Chemistry");
        h1.put("C",subjects);

        h2.put("Python","111");
        h2.put("Math","222");
        h2.put("C","333");
        h2.put("C++","444");

        for(Map.Entry<String, List<String>> m:h1.entrySet()){
            System.out.println(m.getKey()+" "+m.getValue());
        }

        for(Map.Entry<String, String> m:h2.entrySet()){
            System.out.println(m.getKey()+" "+m.getValue());
        }

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter a student: ");
        String s = sc.nextLine();

        System.out.println("Faculties are: ");
        h1.forEach((k, v) -> {
            if(k.equals(s))
            v.forEach(w -> {for(Map.Entry<String, String> m:h2.entrySet()){
                if(m.getKey().equals(w))
                    System.out.println(m.getValue());
            }});
        });

        sc.close();
    }
}
