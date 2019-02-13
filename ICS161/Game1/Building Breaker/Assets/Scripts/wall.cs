using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class wall : MonoBehaviour {

    public Vector3 bounciness;
	// Use this for initialization
	void Start () {
        gameObject.GetComponent<Renderer>().enabled = false;
    }



}
