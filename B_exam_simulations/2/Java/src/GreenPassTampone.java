public class GreenPassTampone extends GreenPass {

    public enum tamponi {TAMPONE1, TAMPONE2, TAMPONE3};
    tamponi tipoTampone;

    GreenPassTampone() {
        this.tipoTampone = tamponi.TAMPONE1;
    }

    GreenPassTampone(final String codiceFiscale, final Data data, final tamponi tampone_par) {
        super(codiceFiscale, data);
        this.tipoTampone = tampone_par;
    }

    @Override
    public String toString() {
        return super.toString() + ", " + this.tipoTampone;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof GreenPassTampone) {
            GreenPassTampone other = (GreenPassTampone) obj;
            return this.codiceFiscale.equals(other.codiceFiscale)
                    && this.data.equals(other.data)
                    && this.tipoTampone == other.tipoTampone;
        }

        return false;
    }

}
