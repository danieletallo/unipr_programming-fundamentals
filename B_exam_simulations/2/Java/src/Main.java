public class Main {
    public static void main(String[] args) {
        // Test della classe Data
        Data data1 = new Data(1, 6, 2023);
        Data data2 = new Data(15, 6, 2023);
        Data data3 = new Data(10, 6, 2023);
        System.out.println("Data1: " + data1);
        System.out.println("Data2: " + data2);
        System.out.println("Data3: " + data3);
        System.out.println("Data1 equals Data2? " + data1.equals(data2));
        System.out.println("Data1 equals Data3? " + data1.equals(data3));
        System.out.println();

        // Test della classe GreenPass
        GreenPass greenPass1 = new GreenPass("ABC123", data1);
        GreenPass greenPass2 = new GreenPass("DEF456", data2);
        GreenPass greenPass3 = new GreenPass("ABC123", data1);
        System.out.println("GreenPass1: " + greenPass1);
        System.out.println("GreenPass2: " + greenPass2);
        System.out.println("GreenPass3: " + greenPass3);
        System.out.println("GreenPass1 equals GreenPass2? " + greenPass1.equals(greenPass2));
        System.out.println("GreenPass1 equals GreenPass3? " + greenPass1.equals(greenPass3));
        System.out.println();

        // Test della classe GreenPassTampone
        GreenPassTampone greenPassTampone1 = new GreenPassTampone("ABC123", data1, GreenPassTampone.tamponi.TAMPONE1);
        GreenPassTampone greenPassTampone2 = new GreenPassTampone("DEF456", data2, GreenPassTampone.tamponi.TAMPONE2);
        GreenPassTampone greenPassTampone3 = new GreenPassTampone("ABC123", data1, GreenPassTampone.tamponi.TAMPONE1);
        System.out.println("GreenPassTampone1: " + greenPassTampone1);
        System.out.println("GreenPassTampone2: " + greenPassTampone2);
        System.out.println("GreenPassTampone3: " + greenPassTampone3);
        System.out.println("GreenPassTampone1 equals GreenPassTampone2? " + greenPassTampone1.equals(greenPassTampone2));
        System.out.println("GreenPassTampone1 equals GreenPassTampone3? " + greenPassTampone1.equals(greenPassTampone3));
        System.out.println();

        // Test della classe GreenPassVaccino
        GreenPassVaccino greenPassVaccino1 = new GreenPassVaccino("ABC123", data1, GreenPassVaccino.vaccini.VACCINO1);
        GreenPassVaccino greenPassVaccino2 = new GreenPassVaccino("DEF456", data2, GreenPassVaccino.vaccini.VACCINO2);
        GreenPassVaccino greenPassVaccino3 = new GreenPassVaccino("ABC123", data1, GreenPassVaccino.vaccini.VACCINO1);
        System.out.println("GreenPassVaccino1: " + greenPassVaccino1);
        System.out.println("GreenPassVaccino2: " + greenPassVaccino2);
        System.out.println("GreenPassVaccino3: " + greenPassVaccino3);
        System.out.println("GreenPassVaccino1 equals GreenPassVaccino2? " + greenPassVaccino1.equals(greenPassVaccino2));
        System.out.println("GreenPassVaccino1 equals GreenPassVaccino3? " + greenPassVaccino1.equals(greenPassVaccino3));
        System.out.println();

        // Test della classe PersonaConGreenPass
        PersonaConGreenPass persona1 = new PersonaConGreenPass("ABC123");
        try {
            persona1.addGreenPass(greenPass1);
            persona1.addGreenPass(greenPassTampone1);
            persona1.addGreenPass(greenPassVaccino1);
            System.out.println("Persona1: " + persona1);
        } catch (GreenPassException e) {
            System.out.println("Errore: " + e.getMessage());
        }

        PersonaConGreenPass persona2 = new PersonaConGreenPass("DEF456");
        try {
            persona2.addGreenPass(greenPass2);
            persona2.addGreenPass(greenPassTampone2);
            persona2.addGreenPass(greenPassVaccino2);
            System.out.println("Persona2: " + persona2);
        } catch (GreenPassException e) {
            System.out.println("Errore: " + e.getMessage());
        }

        PersonaConGreenPass persona3 = new PersonaConGreenPass("ABC123");
        try {
            persona3.addGreenPass(greenPass3);
            persona3.addGreenPass(greenPassTampone3);
            persona3.addGreenPass(greenPassVaccino3);
            persona3.addGreenPass(greenPassVaccino3); // ERRORE! :-)
            System.out.println("Persona3: " + persona3);
        } catch (GreenPassException e) {
            System.out.println("Errore: " + e.getMessage());
        }
    }
}
