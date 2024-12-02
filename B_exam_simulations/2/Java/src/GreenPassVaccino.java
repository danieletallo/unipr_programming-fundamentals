public class GreenPassVaccino extends GreenPass {

    public enum vaccini {VACCINO1, VACCINO2, VACCINO3};
    vaccini tipoVaccino;

    GreenPassVaccino() {
        this.tipoVaccino = vaccini.VACCINO1;
    }

    GreenPassVaccino(final String codiceFiscale, final Data data, final vaccini vaccino_par) {
        super(codiceFiscale, data);
        this.tipoVaccino = vaccino_par;
    }

    @Override
    public String toString() {
        return super.toString() + ", " + this.tipoVaccino;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof GreenPassVaccino) {
            GreenPassVaccino other = (GreenPassVaccino) obj;
            return this.codiceFiscale.equals(other.codiceFiscale)
                   && this.data.equals(other.data)
                   && this.tipoVaccino == other.tipoVaccino;
        }

        return false;
    }

}
