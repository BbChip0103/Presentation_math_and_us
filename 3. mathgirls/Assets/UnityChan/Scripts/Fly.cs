using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Fly : MonoBehaviour {

	public float height, speed;

	private float vertical_start, horizontal_start;
	private int direction = 1, cnt = 0, cnt_limit = 50;

	// Use this for initialization
	void Start () {
		cnt_limit = (int)(cnt_limit / speed);

		vertical_start = this.transform.position.y;
		horizontal_start = this.transform.position.x;
	}

	void FixedUpdate() {
		transform.position = Vector3.up * direction * height * cnt / (cnt_limit - 1);
		transform.position += Vector3.up * vertical_start + Vector3.right * horizontal_start;
		if (direction == -1) {
			transform.position += Vector3.up * height;
		}
		if (cnt >= cnt_limit - 1) {
			direction = -direction;
			cnt = 0;
		} else {
			cnt++;
		}
	}
}
