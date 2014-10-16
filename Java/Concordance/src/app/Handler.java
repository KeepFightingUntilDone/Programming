package src.app;

import java.util.HashMap;

public abstract class Handler {
	protected Handler successor;
	
	public void SetSuccessor(Handler successor){
		this.successor = successor;
	}
	
	public void UpdateConcordance(String word, boolean newline, HashMap<String, ConcordanceDataStruct> concordance) {
		if (!concordance.containsKey(word)) {
			concordance.put(word, new ConcordanceDataStruct());
		}
			
		concordance.get(word).frequency ++;
			
		if (newline) {
			ConcordanceDataStruct.CurentLineNumber ++;
		}
		
		concordance.get(word).lineNumbers.add(ConcordanceDataStruct.CurentLineNumber);
	}
	
	public abstract void HandleRequest(String request, String nextWord, HashMap<String, ConcordanceDataStruct> concordance);
}
