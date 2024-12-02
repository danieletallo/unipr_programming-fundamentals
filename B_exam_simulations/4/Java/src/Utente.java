public class Utente {

    private String nome;
    private String cognome;

    public Utente() {
        this.nome = "Null";
        this.cognome = "Null";
    }

    public Utente(final String nome, final String cognome) {
        this.nome = nome;
        this.cognome = cognome;
    }

    @Override
    public String toString() {
        return this.nome + " " + this.cognome;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof Utente) {
            Utente other = (Utente) obj;
            return this.nome.equals(other.nome) && this.cognome.equals(other.cognome);
        }
        return false;
    }


}
