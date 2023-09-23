package pkg2;

public class HighRiseCondo extends Condo {

    public HighRiseCondo(int price, double area) {
        super(price, area);
        System.out.println("HighCon1");
    }public static void main(String[] args) {
        HighRiseCondo condo = new HighRiseCondo(100, 10);
    }
}