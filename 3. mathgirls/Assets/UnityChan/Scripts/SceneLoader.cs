using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public class SceneLoader : MonoBehaviour {

	void OnGUI()
	{
		GUI.Box(new Rect(10 , Screen.height - 100 ,100 ,90), "화면 설정");
		if(GUI.Button( new Rect(20 , Screen.height - 65 ,80, 40), "돌아가기"))
			SceneManager.LoadScene("Title");
	}
}
