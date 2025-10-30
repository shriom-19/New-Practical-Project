import java.util.*;

class Student {
    int id;
    String name;
    String grade;

    public Student(int id, String name, String grade) {
        this.id = id;
        this.name = name;
        this.grade = grade;
    }
}

class StudentManager {
    ArrayList<Student> studentList = new ArrayList<>();

    void addStudent(Student student) {
        studentList.add(student);
    }

    void displayAllStudents() {
        if (studentList.isEmpty()) {
            System.out.println("No students available.");
        } else {
            for (Student s : studentList) {
                System.out.println(s.id + " | " + s.name + " | " + s.grade);
            }
        }
    }

    Student searchStudent(int id) {
        for (Student s : studentList) {
            if (s.id == id)
                return s;
        }
        return null;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StudentManager manager = new StudentManager();

        while (true) {
            System.out.println("\n--- Student Management Menu ---");
            System.out.println("1. Add Student");
            System.out.println("2. Display All Students");
            System.out.println("3. Search Student");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine();

            switch (choice) {
                case 1:
                    System.out.print("Enter ID: ");
                    int id = sc.nextInt();
                    sc.nextLine();
                    System.out.print("Enter Name: ");
                    String name = sc.nextLine();
                    System.out.print("Enter Grade: ");
                    String grade = sc.nextLine();
                    manager.addStudent(new Student(id, name, grade));
                    System.out.println("Student added successfully.");
                    break;

                case 2:
                    manager.displayAllStudents();
                    break;

                case 3:
                    System.out.print("Enter ID to search: ");
                    int searchID = sc.nextInt();
                    Student found = manager.searchStudent(searchID);
                    if (found != null)
                        System.out.println("Found: " + found.name + " | Grade: " + found.grade);
                    else
                        System.out.println("Student not found.");
                    break;

                case 4:
                    System.out.println("Exiting program...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice.");
            }
        }
    }
}

