public class Partito implements Eleggibile {

    private String nome;
    private int numVoti;

    public Partito(final String nome) {
        this.nome = nome;
        this.numVoti = 0;
    }

    public void vota() {
        this.numVoti++;
    }

    public int getVoti() {
        return this.numVoti;
    }

    public String getNome() {
        return this.nome;
    }

    @Override
    public String toString() {
        return this.nome + " " + this.numVoti;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof Partito) {
            Partito other = (Partito) obj;
            return this.nome.equals(other.nome) && this.numVoti == other.numVoti;
        }
        return false;
    }

}
