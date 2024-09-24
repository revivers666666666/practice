
public class Dog{
    int size;
    String breed;
    String name;
    void bark(){
        System.out.println("bark!");
    }
    public static void main(String[] args){
        Dog d = new Dog();
        d.size = 40 ;
        d.bark();
        King king = new King();
    king.onername = "dennis";
    king.own();
    }
    

}

class King{
    String onername;

    void own(){
        System.out.println("The dog is own by"+ onername);
    } 
}