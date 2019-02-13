using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class camera_Movement : MonoBehaviour {

    public GameObject player;
    public float maxDist;

    private Vector3 offset;
    private float moveVec;
    private Vector3 start;

	// Use this for initialization
	void Start () {
        start = transform.position;
        offset = transform.position - player.transform.position;
	}
	
	// Update is called once per frame
	void LateUpdate () {
        if (player == null)
            transform.position = start;
        else
            transform.position = player.transform.position + offset;
	}
}
