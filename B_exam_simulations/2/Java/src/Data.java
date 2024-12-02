public class Data {
    private final int giorno;
    private final int mese;
    private final int anno;

    public Data() {
        this.giorno = 1;
        this.mese = 1;
        this.anno = 2023;
    }
    public Data (int giorno, int mese, int anno) {
        if (valida(giorno, mese, anno)) {
            this.giorno = giorno;
            this.mese = mese;
            this.anno = anno;
        } else
            throw new RuntimeException();
    }
    public boolean valida(int giorno, int mese, int anno) {
        // Controllo sulla validità di giorno, mese e anno
        if (anno < 0 || mese < 1 || mese > 12 || giorno < 1)
            return false;

        int[] giorniPerMese = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0))
            giorniPerMese[1] = 29; // Anno bisestile, febbraio ha 29 giorni

        if (giorno > giorniPerMese[mese - 1])
            return false;

        return true;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + giorno;
        result = prime * result + mese;
        result = prime * result + anno;
        return result;
    }

    @Override
    public String toString () {
        return giorno + " / " + mese + " / " + anno;
    }

    @Override
    public boolean equals ( Object obj ) {
        if (this == obj)
            return true ;
        if (obj == null)
            return false ;
        if (getClass() != obj.getClass())
            return false;
        Data other = (Data) obj ;
        return anno == other.anno && giorno == other.giorno && mese == other.mese;
    }
}