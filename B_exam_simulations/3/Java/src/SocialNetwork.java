import java.util.HashSet;
import java.util.Set;

public class SocialNetwork {

    private String nomeSocial;
    private Set<User> utenti;

    public SocialNetwork() {
        this.nomeSocial = "Null";
        this.utenti = new HashSet<>();
    }

    public SocialNetwork(final String nomeSocial) {
        this.nomeSocial = nomeSocial;
        this.utenti = new HashSet<>();
    }

    public void addUser(User utente) throws SocialNetworkException {
        if(utenti.contains(utente))
            throw new SocialNetworkException("Utente gia' iscritto al social!");
        utenti.add(utente);
    }
}
