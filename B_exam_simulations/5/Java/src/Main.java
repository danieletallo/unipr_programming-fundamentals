public class Main {

    public static void main(String[] args) throws CloneNotSupportedException {

        // Creazione di una nuova elezione
        Elezione elezione = new Elezione();

        Partito partito1 = new Partito("Partito A");
        Partito partito2 = new Partito("Partito B");
        Partito partito3 = new Partito("Partito C");
        Partito partito4 = new Partito("Partito D");

        Coalizione coalizione1 = new Coalizione("Coalizione X", new Partito[]{partito1, partito2});
        Coalizione coalizione2 = coalizione1.clone();
        coalizione2.add(partito4);

        System.out.println(coalizione1);
        System.out.println(coalizione2);

    }
}
