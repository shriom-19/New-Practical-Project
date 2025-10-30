package experiment_4;

public class overloading {

    String message;
    int number;

    public overloading() {
        this.message = "No message provided.";
        this.number = 0;
        System.out.println("Default constructor called.");
    }

    public overloading(String msg) {
        this.message = msg;
        this.number = 0;
        System.out.println("Constructor with String parameter called: " + msg);
    }

    public overloading(int num) {
        this.message = "Default message.";
        this.number = num;
        System.out.println("Constructor with int parameter called: " + num);
    }

    public overloading(String msg, int num) {
        this.message = msg;
        this.number = num;
        System.out.println("Constructor with String and int parameters called: " + msg + ", " + num);
    }

    public void displayInfo() {
        System.out.println("Displaying info: Message - " + this.message + ", Number - " + this.number);
    }

    public void displayInfo(String prefix) {
        System.out.println(prefix + ": Message - " + this.message + ", Number - " + this.number);
    }

    public int add(int a, int b) {
        return a + b;
    }

    public double add(double a, double b) {
        return a + b;
    }

    public static void main(String[] args) {
        overloading obj1 = new overloading();
        overloading obj2 = new overloading("Hello World!");
        overloading obj3 = new overloading(123);
        overloading obj4 = new overloading("Custom Message", 456);

        System.out.println("\n--- Demonstrating Method Overloading ---");

        obj1.displayInfo();
        obj2.displayInfo("Prefix Info");

        System.out.println("Sum of two integers: " + obj1.add(5, 10));
        System.out.println("Sum of two doubles: " + obj1.add(5.5, 10.2));
    }
}

