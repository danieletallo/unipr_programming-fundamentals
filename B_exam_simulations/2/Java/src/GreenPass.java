public class GreenPass {

    protected String codiceFiscale;
    protected Data data;

    GreenPass() {
        this.codiceFiscale = "Null";
        this.data = new Data();
    }

    GreenPass(final String codiceFiscale_par, final Data data_par) {
        this.codiceFiscale = codiceFiscale_par;
        this.data = data_par;
    }

    public String getCodiceFiscale() {
        return this.codiceFiscale;
    }
    @Override
    public String toString() {
        return this.codiceFiscale + ", " + this.data.toString();
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof GreenPass) {
            GreenPass other = (GreenPass) obj;
            return this.codiceFiscale.equals(other.codiceFiscale) && this.data.equals(other.data);
        }

        return false;
    }

}
