import MyPackage.Helper;

public class MainProgram {
    public static void main(String[] args) {
        Helper utility = new Helper();
        String message = utility.greet("User1");
        System.out.println(message);
    }
}
