import java.util.HashSet;
import java.util.Set;

public class Coalizione implements Eleggibile, Cloneable, Comparable<Coalizione> {

    private String nome;
    private Set<Partito> insieme;

    public Coalizione(final String nome, final Partito[] partiti) {
        this.nome = nome;
        this.insieme = new HashSet<Partito>();
        for(int i=0; i<partiti.length; i++) {
            this.insieme.add(partiti[i]);
        }
    }

    public void add(Partito p) {
        this.insieme.add(p);
    }
    public int getVoti() {
        int numVoti = 0;
        for(Partito part : insieme) {
            numVoti += part.getVoti();
        }
        return numVoti;
    }

    public String getNome() {
        return this.nome;
    }

    public Set<Partito> getPartiti() {
        return insieme;
    }

    @Override
    public String toString() {
        return this.nome + " " + insieme;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof Coalizione) {
            Coalizione other = (Coalizione) obj;
            return this.nome.equals(other.nome) && this.insieme.equals(other.insieme);
        }
        return false;
    }

    @Override
    public Coalizione clone() throws CloneNotSupportedException {
        Coalizione clone = (Coalizione) super.clone();
        clone.insieme = new HashSet<>(this.insieme);
        return clone;
    }

    @Override
    public int compareTo(Coalizione other) {
        if(this.getVoti() < other.getVoti())
            return -1;
        else if(this.getVoti() > other.getVoti())
            return 1;
        return 0;
    }

}
