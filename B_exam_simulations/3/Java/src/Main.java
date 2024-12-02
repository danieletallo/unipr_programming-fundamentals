public class Main {
    public static void main(String[] args) {
        try {
            // Creazione di alcuni utenti
            User user1 = new NormalUser("Alice", "Smith");
            User user2 = new NormalUser("Bob", "Johnson");
            User user3 = new PremiumUser();
            User user4 = new NormalUser("Charlie", "Brown");
            User user5 = new PremiumUser();

            // Creazione di un social network
            SocialNetwork socialNetwork = new SocialNetwork("MySocialNetwork");

            // Aggiunta degli utenti al social network
            socialNetwork.addUser(user1);
            socialNetwork.addUser(user2);
            socialNetwork.addUser(user3);
            socialNetwork.addUser(user4);
            socialNetwork.addUser(user5);

            // Aggiunta di amici per gli utenti
            ((NormalUser) user1).addFriend(user2);
            ((NormalUser) user1).addFriend(user3);
            ((NormalUser) user2).addFriend(user1);
            ((NormalUser) user2).addFriend(user4);
            ((PremiumUser) user3).addFollower(user1);
            ((PremiumUser) user3).addFollower(user2);

            // Stampa dei dettagli degli utenti
            System.out.println("Dettagli degli utenti:");
            System.out.println(user1);
            System.out.println(user2);
            System.out.println(user3);
            System.out.println(user4);
            System.out.println(user5);

        } catch (SocialNetworkException e) {
            System.out.println("Eccezione nell'operazione: " + e.getMessage());
        }
    }
}
