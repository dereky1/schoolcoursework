using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class reset : MonoBehaviour {

    public float points;
    public GameObject ball;
    private float score = 0;

	// Update is called once per frame
	void Update () {
		if(Input.GetKeyDown("r"))
            Application.LoadLevel(Application.loadedLevel);

        if(points > 0 && score == 0)
        {
            StartCoroutine(score_count());
            score = 1;
        }
    }

    private void OnTriggerEnter(Collider other)
    {
        if (other.gameObject.tag == "Player")
        {
            Destroy(other.gameObject);
            if(points == 0)
                StartCoroutine(score_count());
        }
        else if (other.gameObject.tag == "Building")
        {
            Destroy(other.gameObject);
            points++;
        }
    }

    IEnumerator score_count()
    {
        yield return new WaitForSeconds(10); 

        var scoreText = new GameObject("Text3D");
        var textMesh = scoreText.AddComponent<TextMesh>();
        scoreText.AddComponent<MeshRenderer>();
        string s = string.Format("SCORE : {0} : {1:0.00}%\nPress R to Restart", points, points/(33+28)*100.00f);
        textMesh.text = s;
        textMesh.color = Color.black;

        Destroy(ball);
    }
}
