import java.util.Set;
import java.util.HashSet;

public class Persona {

    private final String nome;
    private final String cognome;

    private final Set<MetodoPagamento> metodiPag;

    public Persona(final String nome, final String cognome) {
        this.nome = nome;
        this.cognome = cognome;
        this.metodiPag = new HashSet<>();
    }

    public void aggiungiMetodoPagamento(MetodoPagamento metodo) {
        this.metodiPag.add(metodo);
    }

    public void paga(MetodoPagamento m, final double importo) {
        for(MetodoPagamento metodo : this.metodiPag)
            if(metodo.equals(m))
                metodo.decrementa(importo);
    }
}
