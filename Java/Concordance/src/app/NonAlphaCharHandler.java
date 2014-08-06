package src.app;

import java.util.HashMap;

public class NonAlphaCharHandler extends Handler {
	
	@Override
	public void HandleRequest(String request, String nextWord, HashMap<String, ConcordanceDataStruct> concordance) {
		// Remove semicolon (and other non-alpha chars if applicable in the future) at the end of the words
		if (request.charAt(request.length() - 1) == ':')
		{
			request = request.substring(0, request.length() - 1);
		}
		
		UpdateConcordance(request, false, concordance);
	}
	
}
