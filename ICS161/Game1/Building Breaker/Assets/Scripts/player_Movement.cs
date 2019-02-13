using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class player_Movement : MonoBehaviour {

    public float speed;
    public float flight = 0;

    public GameObject tex;

    private Rigidbody rb;
	// Use this for initialization
	void Start () {
        rb = GetComponent<Rigidbody>();
        StartCoroutine(textBye());
	}
	
	// Update is called once per frame
	void Update () {
        float moveVec = 0;

        if (Input.GetKeyDown("space"))
            moveVec = 75;
        
        float horzVec = Input.GetAxis("Horizontal");
        float vertVec = Input.GetAxis("Vertical");

        moveVec *= speed;
        Vector3 movement = new Vector3(horzVec, 0, vertVec);
        rb.AddForce(movement * speed);

        if (flight == 0)
        {
            movement = new Vector3(0, moveVec/20, moveVec);
            rb.AddForce(movement * speed);
        }

        if (Input.GetKeyUp("space"))
            flight = 1;

        Vector3 windMove;

        if(Input.GetKeyDown("a") && flight == 1)
        {
            windMove = new Vector3(-100, 0, 0);
            rb.AddForce(windMove);
        }

        if (Input.GetKeyDown("d") && flight == 1)
        {
            windMove = new Vector3(100, 0, 0);
            rb.AddForce(windMove);
        }
    }

    IEnumerator textBye()
    {
        yield return new WaitForSeconds(5);

        Destroy(tex);
    }

}
