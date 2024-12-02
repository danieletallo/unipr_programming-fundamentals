public interface MetodoPagamento {

    public double verificaSaldo();
    public void incrementa(final double importo);
    public void decrementa(final double importo);

}
