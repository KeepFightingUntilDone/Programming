package src.app;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;

class ConcordanceDataStruct {
	static int CurentLineNumber = 1;
	int frequency = 0;
	ArrayList<Integer> lineNumbers = new ArrayList<Integer>();
}

public class Concordance {

	public void GetConcordance(String inputWords)
	{
		Handler whiteSpaceHandler = new WhiteSpaceHandler();
		Handler sentenceTerminatorHandler = new SentenceTerminatorHandler();
		Handler nonAlphaCharHandler = new NonAlphaCharHandler();
		
		whiteSpaceHandler.SetSuccessor(sentenceTerminatorHandler);
		sentenceTerminatorHandler.SetSuccessor(nonAlphaCharHandler);
		
		HashMap<String, ConcordanceDataStruct> concordance = new HashMap<String, ConcordanceDataStruct>();
		
		String[] tokens = inputWords.split(",| |\n");
		for (int i=0; i<tokens.length; i++)
		{
			// System.out.println(tokens[i]);
			whiteSpaceHandler.HandleRequest(tokens[i], i==tokens.length-1?null:tokens[i+1], concordance);
		}
		
		// Print the results
		Iterator<String> keySetIterator = concordance.keySet().iterator();

		int index = 0;
		while (keySetIterator.hasNext()){
			index ++;
			String key = keySetIterator.next();
			System.out.print(index + ". " + key + "\t{" + concordance.get(key).frequency + ":");
			for (int i=0; i<concordance.get(key).lineNumbers.size(); i++) {
				System.out.print(concordance.get(key).lineNumbers.get(i) + (i==concordance.get(key).lineNumbers.size()-1?"}":","));
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		final String inputWords = "Given an arbitrary text document written in English, write a program that will generate a concordance, i.e. an alphabetical list of all word occurrences, labeled with word frequencies. Bonus: label each word with the sentence numbers in which each occurrence appeared.";
		Concordance concordance = new Concordance();
		concordance.GetConcordance(inputWords);
	}

}
