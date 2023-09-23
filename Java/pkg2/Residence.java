package pkg2;

public class Residence {
    private String location;

    public Residence() {
        this.location = "Unknown";
        System.out.println("Res1");
    }
    
    public Residence(String location) {
        this.location = location;
        System.out.println("Res2");
    }
}
