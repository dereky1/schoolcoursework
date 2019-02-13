using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class rampAimer : MonoBehaviour {

    public float launchSpeed;
    private Vector3 movement;
    private Rigidbody rb;
    private float launched = 0;

	// Use this for initialization
	void Start () {
        rb = GetComponent<Rigidbody>();
	}
	
	// Update is called once per frame
	void FixedUpdate () {
        if (Input.GetKeyDown("w") && launched == 0)
            launch();
    }

    void launch()
    {
        movement = new Vector3(0, launchSpeed * 100, 0);
        rb.AddForce(movement);
        launched = 1;
    }
}
