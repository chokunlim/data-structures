package pkg3;

public class Player implements Comparable {
    private String name;
    private int health;
    private int level;
    public Player(String name, int health, int level) {
        this.name = name;
        this.health = health;
        this.level = level;
    }
    
    public void setName(String new_name) {
        this.name = new_name;}public String toString() {
            return name;
        }

    public int compareTo(Object o) {
        Player otherPlayer = (Player) o;
        int diff = this.level - otherPlayer.level;
        return diff;
    }

}

