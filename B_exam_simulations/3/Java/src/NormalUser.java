import java.util.HashSet;
import java.util.Set;

public class NormalUser implements User {

    private String nome;
    private String cognome;
    protected Set<User> amici;

    public NormalUser() {
        this.nome = "Null";
        this.cognome = "Null";
        this.amici = new HashSet<>();
    }

    public NormalUser(final String nome, final String cognome) {
        this.nome = nome;
        this.cognome = cognome;
        this.amici = new HashSet<>();
    }

    public void addFriend(User other) throws SocialNetworkException {
        NormalUser amico = (NormalUser) other;
        if(this.equals(amico))
            throw new SocialNetworkException("Non puoi aggiungere te stesso come amico!");
        amici.add(amico);
        amico.amici.add(this);
    }

    public void follow(PremiumUser other) throws SocialNetworkException {
        other.addFollower(this);
    }

    public String getUsername() {
        return this.nome + " " + this.cognome + " " + this.amici.size();
    }

    @Override
    public String toString() {
        return this.getUsername();
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof NormalUser) {
            NormalUser other = (NormalUser) obj;
            return this.nome.equals(other.nome) && this.cognome.equals(other.cognome);
        }
        return false;
    }

}
