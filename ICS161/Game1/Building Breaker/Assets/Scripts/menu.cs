﻿using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class menu : MonoBehaviour {

    // Update is called once per frame
    void Update () {
        if (Input.GetKeyDown("space"))
            UnityEngine.SceneManagement.SceneManager.LoadScene(1);
	}
}
