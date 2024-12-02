import java.util.HashSet;
import java.util.Set;

public class Registro {

    private Set<Iscrizione> iscritti;

    public Registro() {
        this.iscritti = new HashSet<Iscrizione>();
    }

    void add(Iscrizione iscr) {
        for(Iscrizione iscritto: iscritti) {
            if(iscritto.overlapsWith(iscr))
                throw new IscrizioneNonValidaException("No");
        }
        iscritti.add(iscr);
    }

    Registro project(final int annoArchivio) {
        Registro archivio = new Registro();

        for(Iscrizione iscritto: iscritti) {
            if(iscritto.getAnnoInizio() == annoArchivio)
                archivio.add(iscritto);
        }

        return archivio;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Iscrizione iscrizione : iscritti) {
            sb.append(iscrizione.toString()).append("\n");
        }
        return sb.toString();
    }
}
