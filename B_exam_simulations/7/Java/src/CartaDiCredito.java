public class CartaDiCredito implements MetodoPagamento {

    private String numeroCarta;
    private double saldo;

    public CartaDiCredito(final String numeroCarta, final double saldo) {
        this.numeroCarta = numeroCarta;
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
        if(obj instanceof CartaDiCredito) {
            CartaDiCredito other = (CartaDiCredito) obj;
            return this.numeroCarta.equals(other.numeroCarta) && this.saldo == other.saldo;
        }
        return false;
    }
}
