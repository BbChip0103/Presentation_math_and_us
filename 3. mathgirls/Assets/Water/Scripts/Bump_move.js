	// Scroll main texture based on time

var scrollSpeed : float;

function Update () { var offset : float = Time.time * scrollSpeed; GetComponent.<Renderer>().material.SetTextureOffset ("_BumpMap", Vector2(offset,0)); } 