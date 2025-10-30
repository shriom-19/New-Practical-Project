package Experiment;

class Player {
    String name;
    int age;

    Player(String name, int age) {
        this.name = name;
        this.age = age;
    }

    void show() {
        System.out.println("\nPlayer Name: " + name);
        System.out.println("Age: " + age);
    }
}

class CricketPlayer extends Player {
    String type;

    CricketPlayer(String name, String type, int age) {
        super(name, age);
        this.type = type;
    }

    @Override
    public void show() {
        super.show();
        System.out.println("Player Type: " + type);
    }
}

class FootballPlayer extends Player {
    String type;

    FootballPlayer(String name, String type, int age) {
        super(name, age);
        this.type = type;
    }

    @Override
    public void show() {
        super.show();
        System.out.println("Player Type: " + type);
    }
}

class HockeyPlayer extends Player {
    String type;

    HockeyPlayer(String name, String type, int age) {
        super(name, age);
        this.type = type;
    }

    @Override
    public void show() {
        super.show();
        System.out.println("Player Type: " + type);
    }
}

class Main {
    public static void main(String[] args) {
        CricketPlayer c = new CricketPlayer("Ameer", "Cricket", 25);
        FootballPlayer f = new FootballPlayer("Arun", "Football", 25);
        HockeyPlayer h = new HockeyPlayer("Ram", "Hockey", 25);
        c.show();
        f.show();
        h.show();
    }
}

