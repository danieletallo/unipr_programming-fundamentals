public class Iscrizione {
    private Utente iscritto;
    private int meseInizio;
    private int annoInizio;
    private int meseFine;
    private int annoFine;

    public Iscrizione(final Utente iscritto, final int meseInizio, final int annoInizio, final int meseFine, final int annoFine) {
        if((annoInizio == annoFine && meseInizio > meseFine) ||
           (annoInizio > annoFine) ||
           (annoFine >= annoInizio + 2) ||
           (annoFine == annoInizio + 1 && meseFine > meseInizio))
            throw new IscrizioneNonValidaException("Date non valide!");

        this.iscritto = iscritto;
        this.meseInizio = meseInizio;
        this.annoInizio = annoInizio;
        this.meseFine = meseFine;
        this.annoFine = annoFine;
    }

    public boolean overlapsWith(Iscrizione other) {
        // TO DO
        return false;
    }

    public int getAnnoInizio() {
        return this.annoInizio;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof Iscrizione) {
            Iscrizione other = (Iscrizione) obj;
            return this.iscritto == other.iscritto
                    && this.meseInizio == other.meseInizio
                    && this.annoInizio == other.annoInizio
                    && this.meseFine == other.meseFine
                    && this.annoFine == other.annoFine;
        }
        return false;
    }

    @Override
    public String toString() {
        return this.iscritto.toString() + " " +
                this.meseInizio + "/" + this.annoInizio +
                " -> " + this.meseFine + "/" + this.annoFine;
    }

}