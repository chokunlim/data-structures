package pkg3;
import java.util.Arrays;
public class SimpleMMO {
    public static void main(String[] args) {
        Player p1 = new Player("p1",100, 1);
        Player p2 = new Player("p2",300, 3);
        Player p3 = new Player("p3",200, 2);
        Player [] clan_server1 = {p1, p2, p3};
        Arrays.sort(clan_server1);
        System.out.println(Arrays.toString(clan_server1));
        //ผลลัพธIคือ“[p1, p3, p2]”}} ชื่อไฟล์: Player.java
    }
}