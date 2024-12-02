import java.util.HashSet;
import java.util.Set;

public class PersonaConGreenPass {

    private String codiceFiscale;
    Set<GreenPass> insieme;

    PersonaConGreenPass(final String codiceFiscale) {
        this.codiceFiscale = codiceFiscale;
        insieme = new HashSet<>();
    }

    void addGreenPass(GreenPass greenPass_par) throws GreenPassException {
        if(!(greenPass_par.getCodiceFiscale().equals(this.codiceFiscale)))
            throw new GreenPassException("Codice fiscale diverso!");
        else if(greenPass_par instanceof GreenPassVaccino && insieme.contains(greenPass_par))
            throw new GreenPassException("Hai gia' ottenuto un Green Pass con un vaccino!");
        else {
            insieme.add(greenPass_par);
        }
    }

    @Override
    public String toString() {
        return this.codiceFiscale + "\n" + this.insieme;
    }

    @Override
    public boolean equals(Object obj) {
        if(this == obj)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof PersonaConGreenPass) {
            PersonaConGreenPass other = (PersonaConGreenPass) obj;
            return this.codiceFiscale.equals(other.codiceFiscale)
                   && this.insieme.equals(other.insieme);
        }

        return false;
    }

}
