package src.app;

import java.util.HashMap;

public class SentenceTerminatorHandler extends Handler {

	@Override
	public void HandleRequest(String request, String nextWord, HashMap<String, ConcordanceDataStruct> concordance) {
		// TODO Auto-generated method stub
		if (request.endsWith("."))
		{
			// if next word starts with lower case, means it is still not a terminator
			if (nextWord != null && nextWord.charAt(0) >= 'a' && nextWord.charAt(0) <= 'z')
			{
				UpdateConcordance(request, false, concordance);
			}
			else
			{
				UpdateConcordance(request.substring(0, request.length()-1), true, concordance);
			}
		}
		else
		{
			this.successor.HandleRequest(request, nextWord, concordance);
		}
	}

}
