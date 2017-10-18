import java.io.*;

public class SaveFiles
{
  public static void main(String[] args)
  {
	try(FileWriter write = new FileWriter(args[0] + "\\savegames.txt")) {
		File list = new File(args[0]);
		if (!list.exists())
			return;	
		File[] saveGames = list.listFiles();
		for(File index : saveGames)
			if (index.isFile() && index.getName().contains(".save"))
				write.write(index.getName() + System.getProperty( "line.separator" ));
		write.flush();
		File result = new File(args[0] + "\\savegames.txt");
		if (result.length() == 0)
			write.write("No savegames found.\n");
	}
	catch(IOException ex) {
		System.err.println(ex.toString());
	}
  }
}