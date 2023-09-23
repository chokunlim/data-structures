public class a {

public static void main(String[] args) 
{
   String myStr = "This isa String";
   System.out.println(myStr.length());

   String subStr = myStr.substring(0, 6);
   System.out.println(subStr);

   char c = myStr.charAt(3);
   System.out.println(c);

   int ind = myStr.indexOf("isa");
   System.out.println(ind);

   System.out.println(myStr.toUpperCase());

   System.out.println(myStr.toLowerCase());
}

}