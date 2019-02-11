import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class XmlAttribute {

	public static String extractAttribute(String attribute, String string) {
		String res = "";
		Pattern pattern = Pattern.compile(attribute + "\\s*=\\s*\"([^\"]*)\"");
		Matcher matcher = pattern.matcher(string);
		if (matcher.find())
			res = matcher.group(1);
		return res;
	}

	public static void main(String[] args) {
		String chaine = "<element attribute1=\"val1\" attribute2 =\"val2\" attribute3= \"val3\" />";
		System.out.println("Attribute 1 = " + extractAttribute("attribute1", chaine));
		System.out.println("Attribute 2 = " + extractAttribute("attribute2", chaine));
		System.out.println("Attribute 3 = " + extractAttribute("attribute3", chaine));
	}
}
