import java.util.HashSet;
import java.util.Set;

public class Elezione {

    private Set<Eleggibile> eleggibili;

    public Elezione() {
        this.eleggibili = new HashSet<Eleggibile>();
    }

    public void add(Eleggibile e) {

        // il Partito o la Coalizione e' gia' iscritto all’elezione
        if (eleggibili.contains(e))
            throw new RuntimeException("Partito o coalizione già iscritto all'elezione");

        // il Partito fa parte di una Coalizione che e' gia' iscritta all’elezione
        else if (e instanceof Partito) {
            for (Eleggibile el : eleggibili)
                if (el instanceof Coalizione) {
                    Coalizione c = (Coalizione) el;
                    if (c.getPartiti().contains(e))
                        throw new RuntimeException("Il partito fa parte di una coalizione già iscritta");

                }

        // la Coalizione contiene un Partito che e' gia' iscritto all’elezione
        } else if (e instanceof Coalizione) {
            Coalizione c = (Coalizione) e;
            for (Partito p : c.getPartiti())
                if (eleggibili.contains(p))
                    throw new RuntimeException("La coalizione contiene un partito che è già iscritto all'elezione");
        }

        // Se tutto va bene aggiungo l'eleggibile agli eleggibili
        eleggibili.add(e);
    }

    public Eleggibile winner() {
        Eleggibile eWinner = null;
        for(Eleggibile e: eleggibili) {
            if(eWinner == null)
                eWinner = e;
            else if(e.getVoti() > eWinner.getVoti())
                eWinner = e;
        }
        return eWinner;
    }
}
