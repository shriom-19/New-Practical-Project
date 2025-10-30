public class Rectangle {
    double width;
    double length;
    double area;
    String colour;

    public Rectangle(double width, double length, String colour) {
        this.width = width;
        this.length = length;
        this.colour = colour;
        find_area();
    }

    public double get_length() {
        return length;
    }

    public double get_width() {
        return width;
    }

    public String get_colour() {
        return colour;
    }

    public void find_area() {
        this.area = this.length * this.width;
    }

    public static void main(String[] args) {
        Rectangle rect1 = new Rectangle(5.0, 10.0, "Red");
        Rectangle rect2 = new Rectangle(6.0, 8.0, "Blue");

        if (rect1.area == rect2.area && rect1.colour.equals(rect2.colour)) {
            System.out.println("Matching Rectangles");
        } else {
            System.out.println("Non-matching Rectangle");
        }
    }
}

