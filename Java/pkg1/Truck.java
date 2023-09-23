package pkg1;

public class Truck extends Vehicle {
    private int numWheel;
    private int numSeat;
    private static String color = "BLUE";
    private double speed;
    public static void main(String[] args) {
        //Truck truck = new Truck();
        //String s = truck.getColor();
        String s = getColor();
        System.out.println("My car color is "+s);
    }

    public static String getColor() {
        return color;
    }
}