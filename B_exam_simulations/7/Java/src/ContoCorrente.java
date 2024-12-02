public class ContoCorrente implements MetodoPagamento, Comparable<ContoCorrente> {

    private String iban;
    private double saldo;

    public ContoCorrente(final String numeroCarta, final double saldo) {
        this.iban = numeroCarta;
        this.saldo = saldo;
    }

    public double verificaSaldo() {
        return this.saldo;
    }

    public void incrementa(final double importo) {
        this.saldo += importo;
    }

    public void decrementa(final double importo) {
        if(this.saldo - importo < 0)
            throw new SaldoNonSufficienteException("Non hai abbastanza danaro!");
        this.saldo -= importo;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == this)
            return true;
        if(obj == null)
            return false;
        if(obj instanceof ContoCorrente) {
            ContoCorrente other = (ContoCorrente) obj;
            return this.iban.equals(other.iban) && this.saldo == other.saldo;
        }
        return false;
    }

    @Override
    public int compareTo(ContoCorrente other) {
        if(this.saldo > other.saldo)
            return 1;
        if(this.saldo < other.saldo)
            return -1;
        return 0;
    }
}
