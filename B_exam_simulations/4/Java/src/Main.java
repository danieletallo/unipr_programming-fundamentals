public class Main {
    public static void main(String[] args) {
        // Creazione degli utenti
        Utente utente1 = new Utente("Mario", "Rossi");
        Utente utente2 = new Utente("Luigi", "Verdi");
        Utente utente3 = new Utente("Giovanni", "Bianchi");

        // Creazione delle iscrizioni
        Iscrizione iscrizione1 = new Iscrizione(utente1, 1, 2023, 12, 2023);
        Iscrizione iscrizione2 = new Iscrizione(utente1, 6, 2023, 7, 2023);
        Iscrizione iscrizione3 = new Iscrizione(utente2, 3, 2023, 5, 2023);
        Iscrizione iscrizione4 = new Iscrizione(utente3, 12, 2022, 12, 2023);

        // Creazione del registro
        Registro registro = new Registro();

        // Aggiunta delle iscrizioni al registro
        registro.add(iscrizione1);
        registro.add(iscrizione2);
        registro.add(iscrizione3);
        registro.add(iscrizione4);

        // Stampa del registro completo
        System.out.println("Registro completo:");
        System.out.println(registro);

        // Proiezione del registro per l'anno 2023
        Registro registroProiettato = registro.project(2023);
        System.out.println("Registro proiettato per l'anno 2023:");
        System.out.println(registroProiettato);
    }
}