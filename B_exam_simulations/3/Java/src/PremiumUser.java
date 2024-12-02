import java.util.HashSet;
import java.util.Set;

public class PremiumUser extends NormalUser implements User {

    private String username;
    private Set<User> followers;

    public PremiumUser() {
        this.username = "Null";
        this.followers = new HashSet<>();
    }

    public void addFollower(User follower) throws SocialNetworkException {
        if(followers.contains(follower))
            throw new SocialNetworkException("L'utente scelto e' gia' un tuo follower!");
        followers.add(follower);
    }

    public String getUsername() {
        return this.username;
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
        if(obj instanceof PremiumUser) {
            PremiumUser other = (PremiumUser) obj;
            return this.username.equals(other.username);
        }
        return false;
    }
}
