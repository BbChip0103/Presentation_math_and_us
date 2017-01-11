using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FlyMath : MonoBehaviour {

	public float height, speed;

	private float vertical_start, horizontal_start;
	private int cnt = 0, cnt_limit = 50;

	void Start () {
		cnt_limit = (int)(cnt_limit / speed * 2);

		vertical_start = this.transform.position.y;
		horizontal_start = this.transform.position.x;
	}

	void FixedUpdate () {
		transform.position = Vector3.up * (2 - (Mathf.Cos(2 * Mathf.PI * cnt / (cnt_limit - 1)) + 1)) / 2 * height;
		transform.position += Vector3.up * vertical_start + Vector3.right * horizontal_start;
		if (cnt >= cnt_limit - 1) {
			cnt = 0;
		}
		else{
			cnt++;
		}
	}
}
